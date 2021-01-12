reset
set xlabel 'round'
set ylabel 'time(ns)'
set title 'performance comparison with optimization O0'     #標題
set term png enhanced font 'Verdana, 10'                    #設定圖片類型
set output 'result_O0.png'
#set format x "%5d"
set xtic 1000                              #顯示的x軸座標與刻度，每次增加多少
set xtics rotate by 45 right                #設定x軸顯示的起始座標，還有每次增加多少
#set grid                                  #在主要刻度畫出格子
#set format x ""                            #不顯示x軸座標


# draw it !!
plot [:][:80]'result_O0' using 2:xtic(1) with points title 'fast_mod',  \
                      '' using 3:xtic(1) with points title 'norm_mod'
