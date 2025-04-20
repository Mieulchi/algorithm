var s: [Int] = readLine()!
    .split(separator: " ")
    .map { Int($0)! }

var arr1 : [Int] = readLine()!
    .split(separator: " ")
    .map { Int($0)! }

var arr2 : [Int] = readLine()!
    .split(separator: " ")
    .map { Int($0)! }

let setB = Set(arr2)
let diff1 = arr1.filter { !setB.contains($0) }

let setA = Set(arr1)
let diff2 = arr2.filter { !setA.contains($0) }

print(diff1.count + diff2.count)