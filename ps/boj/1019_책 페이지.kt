// 1019번 책 페이지
// 분류: 수학
// 문제:
//      1 ~ N까지 수들 쫙 있을 때 사용된 숫자의 개수 구하기
// 풀이:
//      특정 사각 영역의 일의 자리 숫자들의 개수는 동일하다는 규칙을 파악해
//      0으로 끝나는 숫자, 9로 끝나는 숫자로 만들어 숫자 세고 이걸 재귀적으로 반복
class Book(private var lastPage: Int) {

    private var startPage = 1
    private var digit = 1
    private val numCountArray = intArrayOf(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

    fun printNumCountArray() {
        numCountArray.forEach { print("$it ") }
        println()
    }

    private fun countNum(num: Int) {
        var temp = num
        while(temp != 0) {
            numCountArray[temp%10] += digit
            temp /= 10
        }
    }

    private fun leftAdjustZero(): Boolean {
        while(startPage % 10 != 0) {
            countNum(startPage)
            if (startPage == lastPage)
                return true
            startPage += 1
        }
        return false
    }

    private fun rightAdjustNine(): Boolean {
        while(lastPage % 10 != 9) {
            countNum(lastPage)
            if (startPage == lastPage)
                return true
            lastPage -= 1
        }
        return false
    }

    private fun countBlock() {
        val count = ((lastPage/10) - (startPage/10) + 1) * digit
        lastPage /= 10
        startPage /= 10
        for (i in 0 .. 9) {
            numCountArray[i] += count
        }
    }

    fun solution() {
        while(true) {
            if (rightAdjustNine())
                break
            if (leftAdjustZero())
                break
            countBlock()
            digit *= 10
        }
    }
}

fun main() {
    val num = readLine()!!.toInt()
    val book = Book(num)
    book.solution()
    book.printNumCountArray()

}