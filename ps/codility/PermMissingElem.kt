// Codility Lesson 3 PermMissingElem
fun solution(A: IntArray): Int {
    val book = IntArray(A.size+1)
    var ans = 0
    for(v in A){
        book[v-1]++
    }
    for((i, v) in book.withIndex()){
        if(v == 0){
            ans = i+1
        }
    }
    return ans
}

fun main(args: Array<String>) {
    val test = intArrayOf(1,2,3,4,5,6,7,8,10)
    println(solution(test))
}