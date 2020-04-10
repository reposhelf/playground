//: Playground - noun: a place where people can play

import Cocoa

var movieRatings = ["Donnie Darko":4, "Chungking Express":5, "Dark City":4]
print("I have rated \(movieRatings.count) movies");
let darkoRating = movieRatings["Donnie Darko"];
movieRatings["Dark City"] = 5

let oldRating: Int? = movieRatings.updateValue(5, forKey: "Donnie Darko")
if let lastRating = oldRating, currentRating = movieRatings["Donnie Darko"] {
    print("Old rating: \(lastRating); current rating \(currentRating)")
}

movieRatings["The Cabinet of Dr. Caligari"] = 5

let removedRating = movieRatings.removeValueForKey("Dark City")
// or movieRatings["Dark City"] = nil, but you cannot get old value

for (key, value) in movieRatings {
    print("The movie \(key) was rated \(value).")
}

for movie in movieRatings.keys {
    print("User has rated \(movie).")
}

let watchedMovies = Array(movieRatings.keys)

// Challenge
let geogriaZipCodes = [30301, 30302, 30303, 30304, 30305,
                       30306, 30307, 30308, 30309, 30310,
                       30311, 30312, 30313, 30314, 30315]

var states: [String:Array<Int>] = [:]
states["Georgia"] = geogriaZipCodes
for (key, value) in states {
    print("\(key) has the following zip codes: \(value)")
}