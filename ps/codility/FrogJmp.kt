// Codility Lesson 3 FrogJmp
fun solution(X: Int, Y: Int, D: Int): Int {
    return if(X==Y)
        0
    else
        (Y - X - 1 / D) + 1
}

fun main(args: Array<String>) {
    val x = 10
    val y = 85
    val d = 30
    println(solution(x, y, d))
}