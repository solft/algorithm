// 프린터
// 문제:
//      가장 앞의 숫자를 가져와
//      그 숫자보다 큰 숫자가 뒤에 있으면 뒤에 넣고
//      그 숫자가 가장 크거나 같으면 빼는 식으로
//      반복해 초기 위치의 숫자가 몇 번째로 나오는지 구하는 문제
// 풀이:
//      배열은 그대로 두고 인덱스를 증가시키며
//      가장 크면 -1로 변경하고 반복해서
//      해당 위치가 빠질 때 까지 반복
class Solution {
    fun solution(priorities: IntArray, location: Int): Int {
        var answer = 0

        var idx = 0
        var printCounter = 0
        sol@while(true) {
            when(priorities[idx]){
                -1 -> {
                    idx++
                    if (idx >= priorities.size)
                        idx = 0
                }
                priorities.max() -> {
                    priorities[idx] = -1
                    printCounter++

                    if (idx == location) {
                        answer = printCounter
                        break@sol
                    }

                    idx++
                    if (idx >= priorities.size)
                        idx = 0
                }
                else -> {
                    idx++
                    if (idx >= priorities.size)
                        idx = 0
                }
            }
        }

        return answer
    }
}

fun main() {
    val sol = Solution()
    println(sol.solution(intArrayOf(1, 1, 9, 1, 1, 1), 0))
}
