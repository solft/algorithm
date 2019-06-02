

// 13085번 해결 못함
// 브루트포스로는 O(n^2) 시간 초과 -> 다른 방법 생각해볼것
fun main() {
    val n = readLine()!!.toInt()
    val base = readLine()!!.toCharArray()

    var ans = 0
    for(i in 0 until n){
        var position = i
        var char = base.copyOf()
        var removeCounter = 0
        var direction = 1 // 1 = 오른쪽, -1 = 왼쪽
        while(true){
            // game end check
            if(position < 0 || position >= n)
                break

            // 상황에 맞게 증가
            when {
                char[position] == '>' -> {
                    char[position] = 'r'
                    removeCounter++
                    direction = 1
                    position += direction
                }
                char[position] == '<' -> {
                    char[position] = 'r'
                    removeCounter++
                    direction = -1
                    position += direction
                }
                else -> {
                    position += direction
                }
            }
        }
        println("Start $i and removeCounter $removeCounter")
        if(ans < removeCounter)
            ans = removeCounter
    }
    println(ans)
}
