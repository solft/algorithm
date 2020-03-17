import kotlin.math.pow

fun two(power: Int):Int = (2.0).pow(power).toInt()


// 1074번 Z
// 분류: 재귀
// 문제:
//      Z자 모양으로 계속 이동해 나갈 때 정사각형 모양에서
//      주어진 row와 col에는 몇번째로 도착하는지 구하는 문제
// 풀이:
//      현재 위치가 가장 큰 사각형을 4등분 했을 때 어디인지 구하고
//      위치에 해당하는 만큼 칸을 더한 뒤 사각형을 왼쪽 위의 위치에
//      옮긴다고 생각하고 반으로 줄어든 사각형에서 반복한다.
fun z(n: Int, r: Int, c:Int, sol: Int = 0): Int = when (n) {
    1 -> {
        when {
            r == 0 && c == 0 -> 0 + sol
            r == 0 && c == 1 -> 1 + sol
            r == 1 && c == 0 -> 2 + sol
            r == 1 && c == 1 -> 3 + sol
            else -> error("")
        }
    }
    else -> {
        val block = two(2 * (n-1))
        val half = two(n-1)
        when {
            r < half && c < half -> z(n-1, r, c, sol)
            r < half && c >= half -> z(n-1, r, c - half, sol + block)
            r >= half && c < half -> z(n-1, r - half, c, sol + 2 * block)
            r >= half && c >= half -> z(n-1, r - half, c - half, sol + 3 * block)
            else -> error("")
        }
    }
}

fun main() {
    val input = readLine()!!.split(" ").map { it.toInt() }
    val solution = z(input[0], input[1], input[2])
    println(solution)
}