class Solution {

    // build_frame = [x, y, a, b]
    // x = 가로 좌표, y = 세로 좌표
    // a = 0은 기둥, 1은 보
    // b = 0은 삭제, 1은 설치
    fun solution(n: Int, build_frame: Array<IntArray>): Array<IntArray> {

        var answer = mutableListOf<IntArray>()

        for (frame in build_frame) {
            val x = frame[0]
            val y = frame[1]
            val a = frame[2] // 0 = 기둥, 1 = 보
            val b = frame[3] // 0 = 삭제, 1 = 설치

            if (b == 0) {
                val tests = answer.filter { it[0] != x || it[1] != y || it[2] != a }.toMutableList()
                var isDelete = true
                for (test in tests) {
                    if (!isConstruct(tests, test[0], test[1], test[2])) {
                        isDelete = false
                    }
                }

                if (isDelete)
                    answer = tests

            } else if (b == 1) {
                if(isConstruct(answer, x, y, a))
                    answer.add(intArrayOf(x, y, a))
            }
        }

        return answer.sortedWith(compareBy({it[0]}, {it[1]}, {it[2]})).toTypedArray()
    }

    fun isConstruct(state: MutableList<IntArray>, x: Int, y: Int, a: Int): Boolean {
        if (a == 0) {
            if (y == 0)
                return true

            if (state.any { it[2] == 0 && it[1] + 1 == y && it[0] == x})
                return true

            if (state.any { it[2] == 1 && it[1] == y && (it[0] + 1 == x || it[0] == x)})
                return true

        } else if (a == 1) {
            if(state.any { it[2] == 0 && (it[1] == y - 1) && (it[0] == x || it[0] - 1 == x) })
                return true

            if(state.filter { it[2] == 1 && (it[1] == y) && (it[0] + 1 == x || it[0] - 1 == x) }.size == 2)
                return true
        }
        return false
    }
}

fun main() {
    val sol = Solution()
    val array = arrayOf(
        intArrayOf(1,0,0,1),
        intArrayOf(1,1,1,1),
        intArrayOf(2,1,0,1),
        intArrayOf(2,2,1,1),
        intArrayOf(5,0,0,1),
        intArrayOf(5,1,0,1),
        intArrayOf(4,2,1,1),
        intArrayOf(3,2,1,1)
    )
    val result = sol.solution(5, array)

    for(arr in result) {
        arr.forEach { print(it) }
        println()
    }
}