//: Playground - noun: a place where people can play

import Cocoa

//var groceryBag = Set<String>(["Apples", "Oranges", "Pinapple"])
var groceryBag: Set = ["Apples", "Oranges", "Pinapple"]

for food in groceryBag {
    print(food)
}

let hasBananas = groceryBag.contains("Bananas")
let friendsGroceryBag = Set(["Bananas", "Cereal", "Milk", "Oranges"])
let commonGroceryBag = groceryBag.union(friendsGroceryBag)

let roommatesGroceryBag = Set(["Bananas", "Apples", "Cereal", "Toothpaste"])
let itemsToReturn = commonGroceryBag.intersection(roommatesGroceryBag)

let yourSecondBag = Set(["Berries", "Yogurt"])
let roommatesSecondBag = Set(["Grapes", "Honey"])
let disjoint = yourSecondBag.isDisjoint(with: roommatesGroceryBag)

// Challenges
let myCities = Set(["Atlanta", "Chicago", "Jacksonville", "New York", "San Francisko"])
let yourCities = Set(["Chicago", "San Francisko",  "Jacksonville"])
print(myCities.isSuperset(of: yourCities))

var challengeGroceryBag = Set(["Apples", "Oranges", "Pinapple"])
challengeGroceryBag.formUnion(friendsGroceryBag)
challengeGroceryBag.formIntersection(roommatesGroceryBag)
