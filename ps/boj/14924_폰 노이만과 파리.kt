// 14924번 폰 노이만과 파리
// 분류: 수학
// 문제:
//      거리 = 시간 * 속력
// 풀이:
//      총 이동 시간을 구하고 거기에 파리의 속력을 곱한 값을 출력한다
fun main() {
    val num = readLine()!!.split(" ").map { it.toInt() }
    println((num[2]/(2*num[0]))*num[1])
}
