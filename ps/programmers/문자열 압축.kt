class Solution {
    fun solution(s: String): Int {
        var answer = 1010

        for (len in 1 .. s.length) {
            val temp = compress(s, len)
            if (answer > temp)
                answer = temp
        }

        return answer
    }

    fun compress(target: String, size: Int): Int {
        var shortestLength = 1010

        var compressString = ""

        var index = 0
        var num = 1
        while (index < target.length) {

            if (index + size >= target.length) {
                if (num == 1)
                    compressString += target.substring(index)
                else
                    compressString += (num.toString() + target.substring(index))
                break
            }

            val com = target.substring(index, index + size)
            val rest = target.substring(index + size)

            if (rest.startsWith(com)) {
                num++
                index += size
            } else {
                if (num == 1) {
                    compressString += target.substring(index, index+size)
                    index += size
                } else {
                    compressString += (num.toString() + com)
                    num = 1
                    index += size
                }
            }
        }

        if (shortestLength > compressString.length)
            shortestLength = compressString.length

        return shortestLength
    }
}

fun main() {
    val sol = Solution()
    println(sol.solution("xababcdcdababcdcd"))
}