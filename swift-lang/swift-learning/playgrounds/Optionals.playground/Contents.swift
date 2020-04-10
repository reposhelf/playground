//: Playground - noun: a place where people can play

import Cocoa

var errorCodeString: String?
errorCodeString = "404"
var errorDescription: String?
if let theError = errorCodeString, errorCodeInteger = Int(theError)
    where errorCodeInteger == 404 {
    errorDescription = ("\(errorCodeInteger + 200): the requested resource was not found.")
}
var upCaseErrorDescription = errorDescription?.uppercaseString
errorDescription
upCaseErrorDescription?.appendContentsOf(" PLEASE TRY AGAIN.")
upCaseErrorDescription
let description = errorDescription ?? "No Error."

// Challenge
let crashCause: String?
crashCause = nil
let variable = crashCause!