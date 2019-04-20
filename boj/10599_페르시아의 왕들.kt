// boj 10599번 페르시아의 왕들
// 단순 뺄샘
fun main() {
    while(true) {
        val input = readLine()!!.split(" ").toTypedArray()
        val year = input.map { it.toInt() }
        if(year[0] == 0 && year[1] == 0 && year[2] == 0 && year[3] == 0)
            break
        println("${year[2]-year[1]} ${year[3]-year[0]}")
    }
}