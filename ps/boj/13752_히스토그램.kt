// 13752번 히스토그램
// 풀이:
//      간단한 구현 문제
fun drawHist(h: Int) {
    repeat(h){
        print("=")
    }
    println()
}

fun main() {
    val n = readLine()!!.toInt()
    val histogram = IntArray(100)
    for (i in 0 until n)
        histogram[i] = readLine()!!.toInt()
    for (i in 0 until n)
        drawHist(histogram[i])
}