
// 15184번 Letter Count
// 문제:
//      문장에 쓰인 알파벳 개수 카운팅 문제
// 풀이:
//      단순 구현
//      전부 소문자로 바꿔주고
//      숫자나 공백, 문자 체크만 해주면 됨
fun printStar(x: Int){
    repeat(x){
        print("*")
    }
    println()
}

fun main() {
    val line = readLine()!!
    val target = line.toLowerCase()

    val alphabet = IntArray(26)
    for (i in target)
        if(i in 'a'..'z')
            alphabet[i.toInt()-'a'.toInt()]++
    for((i, e) in alphabet.withIndex()) {
        print("${(i+65).toChar()} | ")
        printStar(e)
    }
}