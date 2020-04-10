//: Playground - noun: a place where people can play

import Cocoa

let playground = "Hello, playground"

var mutablePlayground = "Hello, mutable playground"
mutablePlayground += "!"
for c: Character in mutablePlayground.characters {
    print("'\(c)'")
}

let oneCoolDude = "\u{1F60E}"

let aAcute = "\u{0061}\u{0301}"

for scalar in playground.unicodeScalars {
    print(scalar.value)
}

let aAcutePrecomposed = "\u{00E1}"

let b = (aAcute == aAcutePrecomposed)

print("aAcute: \(aAcute.characters.count);",
    "aAcutePrecomposed \(aAcutePrecomposed.characters.count)")

let fromStart = playground.startIndex
let toPosition = 4
let end = fromStart.advancedBy(toPosition)
let fifthCharacter = playground[end]
let range = fromStart...end
let firstFive = playground[range]

let unicodeHello = "\u{0048}\u{0065}\u{006C}\u{006C}\u{006F}"