//
//  HelloLib.swift
//  test_sic
//
//  Created by SergeyBrazhnik on 09.11.2020.
//

import Foundation
import KeychainSwift
import GRPC
import NIO
import OpenSSL


public class HelloLib {
    
    static let keychain = KeychainSwift(keyPrefix: "HelloLib")
    
    public class func helloFunc(){
        print("helloFunc called")
    }

    public class func saveString(key: String, value: String) {
        keychain.set(value, forKey: key,withAccess: .accessibleWhenPasscodeSetThisDeviceOnly)
    }

    public class func getString(key: String) -> String? {
        keychain.get(key)
    }
    
    public class func getTestGRPCCLient(){
        let group = MultiThreadedEventLoopGroup(numberOfThreads: 1)
        let channel = ClientConnection.insecure(group: group)
                .withConnectionBackoff(retries: .none)
                .withConnectionBackoff(maximum: .seconds(30))
                .withConnectionTimeout(minimum: .seconds(30))
            .connect(host: "192.168.1.1", port: 8088)
    }
    
    public class func chipher(){
        let ctx = EVP_CIPHER_CTX_new()
//        let source = Array("hello".utf8)
//        MD5(source, source.count, <#T##md: UnsafeMutablePointer<UInt8>!##UnsafeMutablePointer<UInt8>!#>)
    }
}
