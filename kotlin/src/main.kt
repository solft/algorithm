
fun main() {
    val input = readLine()!!.split(" ").map { it.toInt() }
    val x = input[1] - input[3]
    val c = input[2] - input[0]
    if (x == 0) {
        if(c == 0)
            println("YES")
        else
            println("NO")
    }
    else if (c%x == 0 && c/x >= 0)
        println("YES")
    else
        println("NO")
}
