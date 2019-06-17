
// 9713번 Sum of Odd Sequence
// 분류: 수학
// 문제:
//      입력된 수 이하의 홀수 합 구하기
// 풀이:
//      n번째 홀수까지 합 = n^2
fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val num = readLine()!!.toInt()
        println(((num+1)/2)*((num+1)/2))
    }
}
