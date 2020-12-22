const express = require('express')
const mysql = require('mysql')

function connect() {
    const connection = mysql.createConnection({
        host: '172.20.10.3',
        user: 'root',
        password: 'root',
        database: 'app_db',
        port: 9099
    })
    connection.connect()
    return connection
}   

const app = express()
app.use(function(req, res, next) {
    res.header("Access-Control-Allow-Origin", "*")
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    next();
});
app.get("/", (req, res) => {
    res.send('welcome to my server')
});

app.get("/product", (req, res) => {
    const connection = connect()
    const statement = `select * from product`
    connection.query(statement, (error, data) => {
        connection.end()
        res.send(data)
    })
});

app.listen(4000, '0.0.0.0', () => {
    console.log('server started  on port 4000')
})