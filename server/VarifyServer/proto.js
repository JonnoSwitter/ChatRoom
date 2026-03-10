
const path = require('path')//类似于C++中通过include包含头文件，在.js文件中用的是require方式
const grpc = require('@grpc/grpc-js')
const protoLoader = require('@grpc/proto-loader')

const PROTO_PATH = path.join(__dirname, 'message.proto')
const packageDefinition = protoLoader.loadSync(PROTO_PATH, { keepCase: true, longs: String, enums: String, defaults: true, oneofs: true })
const protoDescriptor = grpc.loadPackageDefinition(packageDefinition)

const message_proto = protoDescriptor.message

module.exports = message_proto