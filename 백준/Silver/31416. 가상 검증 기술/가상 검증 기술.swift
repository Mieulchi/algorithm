var n = (Int(readLine()!)!)

for _ in 1...n {
    var arr = readLine()!.split(separator:" ").map{ Int($0)! }
    var ans = arr[1] * arr[3]
    if arr[0] * arr[2] <= arr[1] * arr[3] {
        print(ans)
    }
    else {
        var remain = arr[2] - ans / arr[0]
        var time : Int;
        if (ans % arr[0] == 0) {
            time = ans
        }
        else {
            time = (ans / arr[0] + 1) * arr[0]
            remain = remain - 1
        }

        if remain % 2 == 1 {
            if time > ans {
                ans = ans + arr[0]
            }
            else {
                time = time + arr[0]
            }
        }
        if (ans > time) {
            ans = ans + arr[0] * (remain / 2)
        }
        else {
            ans = time + arr[0] * (remain / 2)
        }
        print(ans)
    }
}
