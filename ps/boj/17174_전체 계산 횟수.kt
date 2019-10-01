
// 17174번 전체 계산 횟수
// 분류: 수학
// 풀이:
//      ans는 N으로 초기화
//      ans에 N/M 값을 계속 더해준다.
//      (N은 계속 N/M 값으로 업데이트)
fun main() {
    val input = readLine()!!.split(" ").map { it.toInt() }
    var n = input[0]
    val m = input[1]

    var ans = n
    while (n > 0) {
        ans += n/m
        n /= m
    }

    println(ans)
}
