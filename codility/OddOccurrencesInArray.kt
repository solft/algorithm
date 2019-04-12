// Codility Lesson 2 OddOccurrencesInArray
fun solution(A: IntArray): Int {
    val a = A
    a.sort()
    var compare = a[0]
    var count = 1

    for (i in 1 until a.size) {
        // 다르면 다음 숫자로 넘어간거
        if(compare != a[i]){
            if(count % 2 == 1)
                return compare
            compare = a[i]
            count = 1
        } else { // 같으면
            count++
        }
    }
    return compare
}

fun main(args: Array<String>) {
    val testCase = intArrayOf(5,3,6,6,3,3,3,4,5,5,5)
    println(solution(testCase))
}