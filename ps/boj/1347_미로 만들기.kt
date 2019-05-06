// 1347번 미로 만들기
// 분류: 구현
// 문제:
//      이동 문자열을 따라 이동했을 때 전체 이동 경로를 포함하는 직사각형을
//      출력하는데 이동한 곳은 '.' 이동하지 못한 벽은 '#'을 출력하는 문제
// 풀이:
//      적당히 큰 배열의 중간에서(어떻게 이동해도 경계를 벗어나지 않을 정도로 큰)
//      입력대로 이동하고 감싸는 직사각형의 좌상단부터 우하단까지 지나갔으면 길,
//      안지나갔으면 벽으로 출력
fun main() {
    val n = readLine()!!.toInt()
    val note = readLine()!!
    val directionY = intArrayOf(1, 0, -1, 0)
    val directionX = intArrayOf(0, -1, 0, 1)

    val miro = Array(200) {CharArray(200)}
    var minX = 100
    var minY = 100
    var maxX = 100
    var maxY = 100

    var x = 100
    var y = 100
    miro[x][y] = '.'
    var direction = 0

    for (c in note) {
        when (c) {
            'R' -> {
                direction += 1
                if (direction >= 4)
                    direction -= 4
            }
            'L' -> {
                direction -= 1
                if (direction < 0)
                    direction += 4
            }
            'F' -> {
                x += directionX[direction]
                if (minX > x)
                    minX = x
                if (maxX < x)
                    maxX = x
                y += directionY[direction]
                if (minY > y)
                    minY = y
                if (maxY < y)
                    maxY = y
                miro[y][x] = '.'
            }
        }
    }

    for(i in minY .. maxY){
        for(j in minX .. maxX){
            if(miro[i][j] == '.')
                print('.')
            else
                print('#')
        }
        println()
    }
}
