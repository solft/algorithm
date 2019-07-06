
// 14909번 양수 개수 세기
// 분류: 카운팅
// 문제:
//      주어진 숫자들 중 양수 개수 구하는 문제
// 풀이:
//      split, map, count 를 활용해서 짧게 풀어보았다.
fun main() {
    println(readLine()!!.split(" ").map { it.toInt() }.count { it > 0 })
}
