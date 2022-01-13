set terminal pngcairo
set encodin utf8

set output 'esquema.png'
unset key

set xrange [0:1]
set yrange [0:1]

set arrow from 0.4,0.2 to 0.4,1 nohead lw 3
set arrow from 0.6,0.2 to 0.6,1 nohead lw 3
set arrow from 0,0.2 to 0.4,0.2 nohead lw 3
set arrow from 0.6,0.2 to 1,0.2 nohead lw 3

set object 1 rectangle from 0.4,0 to 0.6,0.2  
set object 1 fillstyle pattern 1 fillcolor "blue" 

set object 2 rectangle from 0,0.2 to 0.4,1
set object 2 fillstyle pattern 3 fillcolor "grey"
set object 3 rectangle from 0.6,0.2 to 1,1
set object 3 fillstyle pattern 3 fillcolor "grey"

set arrow from 0.4,1 to 0.6,1 nohead lw 6 lc "red"
set label "ρ_{1}" at 0.5,0.95  tc "red" 

set arrow from 0,0 to 0,0.2 nohead lw 6 lc "red"
set label "ρ_{2}" at 0.05,0.1  tc "red"

set arrow from 1,0 to 1,0.2 nohead lw 7 lc "blue"
set label "riu" at 0.9,0.1  tc "blue"

set arrow from 0.2,0.1 to 0.8,0.1 head lw 3
set arrow from 0.5,0.9 to 0.5,0.22 head lw 3

plot -1,-1
