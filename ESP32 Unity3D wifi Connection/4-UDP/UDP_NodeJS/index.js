const dgram = require('dgram')
const server = dgram.createSocket('udp4')
const server2 = dgram.createSocket('udp4')

server.on('error',(error)=>{
    console.log('error on the server \n' + error.message)
    server.close()
})

server.on('listening',()=>{
    const address = server.address()
    console.log(`server is listening on ${address.address}:${address.port}`)
})

server.on('message',(message,senderInfo)=>{
    console.log('Message recieved')
    server.send(message, senderInfo.port,senderInfo.address,()=>{
        console.log(`Message have been sent to ${senderInfo.address}:${senderInfo.port}`)
    })
})
server.bind(5200)




server2.on('error',(error)=>{
    console.log('error on the server \n' + error.message)
    server2.close()
})

server2.on('listening',()=>{
    const address = server2.address()
    console.log(`server is listening on ${address.address}:${address.port}`)
})

server2.on('message',(message,senderInfo)=>{
    console.log('Message recieved')
    server2.send(message, senderInfo.port,senderInfo.address,()=>{
        console.log(`Message have been sent to ${senderInfo.address}:${senderInfo.port}`)
    })
})
server2.bind(5300)
