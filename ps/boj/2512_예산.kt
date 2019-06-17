
// 2512번 예산
// 분류: 이진 탐색
// 문제:
//      숫자 리스트의 합이 예산 이하로 떨어지도록하는
//      상한값의 최댓값 구하기
// 풀이:
//      그냥 합이 총예산 이하인 경우 => 요구 예산의 최대
//      예산 합이 넘치는 경우 => 이진 탐색으로 적절한 상한을 찾는다.
fun main() {
    val n = readLine()!!.toInt()
    val requests = readLine()!!.split(" ").map { it.toInt() }
    val budget = readLine()!!.toInt()

    val max_request = requests.max()!!
    val sum_requests = requests.sum()

    if(sum_requests <= budget)
        println(max_request)
    else {
        var left = 1
        var right = max_request
        var ans = 0

        while(left <= right){
            val mid = (left + right) / 2
            var sum = 0
            for(r in requests)
                sum += if(mid <= r) mid else r
            when {
                sum > budget -> {
                    right = mid - 1
                }
                sum <= budget -> {
                    if(ans < mid)
                        ans = mid
                    left = mid + 1
                }
            }
        }

        println(ans)
    }
}
