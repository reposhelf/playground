//: Playground - noun: a place where people can play

import Cocoa

print("The maximum Int value is \(Int.max).")
print("The minimum Int value is \(Int.min).")
print("The maximum value of 32-bit integer is \(Int32.max).")
print("The minimum value of 32-bit integer is \(Int32.min).")

print("The maximum UInt value is \(UInt.max).")
print("The minimum UInt value is \(UInt.min).")
print("The maximum value of 32-bit unsigned integer is \(UInt32.max).")
print("The minimum value of 32-bit unsigned integer is \(UInt32.min).")

let numberOfPages: Int = 10
let numberOfChapters = 3

let numberOfPeople: UInt = 40
let volumeAdjustment: Int32 = -1000

print(10 + 20)
print(30 - 5)
print(6 * 5)

print(10 + 2 * 5)
print(30 - 5 - 5)
print((10 + 2) * 5)
print(30 - (5 - 5))

print(11 / 3)
print(11 % 3)
print(-11 % 3)

var x = 10
x += 1
print("x has been incremented to \(x)")
x -= 1
print("x has been decremented to \(x)")

let y: Int8 = 120
let z = y &+ 10
print("y &+ 10 is \(z)")

let a: Int16 = 200
let b: Int8 = 50
let c = a + Int16(b)

let d1 = 1.1
let d2: Double = 1.1
let f1: Float = 100.3

print(10.1 + 11.4)
print(11.0 / 3.0)
print(12.4 % 5.0)

if d1 == d2 {
    print("d1 and d2 are the same")
}

print("d1 + 01 is \(d1 + 0.1)")
if d1 + 0.1 == 1.2 {
    print("d1 + 0.1 is equal to 1.2")
}