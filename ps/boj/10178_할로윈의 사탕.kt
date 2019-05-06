// 10178번 할로윈의 사탕
// 분류: 쉬움
// 문제:
//      몫 나머지 구하기 & 출력
// 풀이:
//      그냥 풀면 된다.
fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val c = readLine()!!.split(" ").map { it.toInt() }
        println("You get ${c[0]/c[1]} piece(s) and your dad gets ${c[0]%c[1]} piece(s).")
    }
}
