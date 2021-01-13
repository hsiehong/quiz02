set xlabel 'divisor'
set ylabel 'time(ns)'
set title "comparison on optimize O3"       #modified
set term png enhance font "Verdana, 11"
set output 'result_O3.png'                  #modified
set xtics 1000
set xtics rotate by 45 right
set grid


plot [:][10:30] 'result_O3' using 1:2 with points title 'fastdiv',  \
                        '' using 1:3 with points title 'sysdiv'
                
