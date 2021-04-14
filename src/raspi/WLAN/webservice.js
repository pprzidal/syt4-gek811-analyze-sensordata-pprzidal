if(process.argv.length != 4) {
    console.error("Wrong syntax: node <filename> <ip of net interface> <port>");
    process.exit(1);
}

port = Number(process.argv[3]);

if(isNaN(port)) {
    console.error("Wrong syntax: node <filename> <ip of net interface> <port>");
    process.exit(1);
}

const Influx = require('influx');
const express = require('express');
const app = express()
const client = new Influx.InfluxDB({
    host: 'localhost',
    database: 'tmp36',
    username: 'phillip',
    password: 'password',
    schema: [{
        measurement: 'temperature',
        fields: {
            value: Influx.FieldType.FLOAT
        },
        tags: [
            'host'
        ]
    }]
});

app.use(express.json()) // for parsing application/json
app.use(express.urlencoded({ extended: true }))

app.post('/', (req, res) => {
    console.log(req.body);
    let a = req.body['temperature'];
    if(a === undefined) {
        res.status(400);
        res.send('There was no key called \"temperature\"\n');
        return;
    }
    val = Number(a);
    if(isNaN(val)) {
        res.status(400);
        res.send('Not parseble\n');
        return;
    }
    client.writePoints([{measurement: 'temperature', fields: {value: val},}]).then(() => {console.log("done")});
    console.log(val);
    res.status(200);
    res.send('OK\n');
});

app.listen(port, process.argv[2], () => {
    console.log('hallo');
});