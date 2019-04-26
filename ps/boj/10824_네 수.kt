// boj 10824번 네 수
// 단순 구현. int 범위로는 runtime error 나는 것에 주의
fun main() {
    val input = readLine()!!.split(" ").toTypedArray()
    val front = input[0] + input[1]
    val back = input[2] + input[3]
    println(front.toLong() + back.toLong())
}