
// 10822번 더하기
// 분류: 더하기
// 문제:
//      ,로 구분된 스트링 입력 받아 숫자만 다 더하기
// 풀이:
//      split, map, reduce 활용해서 풀었다.
fun main() {
    val ans = readLine()!!.split(",").map { it.toInt() }.reduce { acc, i -> acc + i }
    println(ans)
}
