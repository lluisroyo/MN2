set terminal gif animate delay 2 size 1500, 1000
set output "animacio.gif"

set key right top

set style line 1 lc rgb "#e88900" lw 1 lt 1 pt 7 ps 3 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #sol
set style line 2 lc rgb "#a79e91" lw 1 lt 1 pt 7 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #mercuri
set style line 3 lc rgb "#b99664" lw 1 lt 1 pt 7 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #venus
set style line 4 lc rgb "#05ffc6" lw 1 lt 1 pt 7 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #terra
set style line 5 lc rgb "#b93c10" lw 1 lt 1 pt 7 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #mart
set style line 6 lc rgb "#ffe367" lw 1 lt 1 pt 7 ps 2 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #jupiter
set style line 7 lc rgb "#b63f00" lw 1 lt 1 pt 7 ps 3 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #gliese
set style line 8 lc rgb "#2de300" lw 1 lt 1 pt 7 ps 3 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #pla de la orbita
f(x,y)= 0


do for [i=1:5000]{
set view 30,20
set xlabel "x"
set ylabel "y"
set zlabel "z"
set xrange[-1.5:1.5]
set yrange[-1.5:1.5]
set zrange[-3:3]

splot "pas".i.".dat" u 19:20:21 w p ls 7 title "Gliese 710",\
"pas".i.".dat" u 19:20:21 with impulses ls 7 title "Gliese 710",\
f(x,y) w l ls 8 title "Plano de la orbita inicial",\
"pas".i.".dat" u 1:2:3 w p ls 1 title "Sol",\
"pas".i.".dat" u 1:2:3 with impulses ls 1 title "Sol",\
"pas".i.".dat" u 4:5:6 w p ls 2 title "Mercurio",\
"pas".i.".dat" u 4:5:6 with impulses ls 2 title "Mercurio",\
"pas".i.".dat" u 7:8:9 w p ls 3 title "Venus",\
"pas".i.".dat" u 7:8:9 with impulses ls 3 title "Venus",\
"pas".i.".dat" u 10:11:12 w p ls 4 title "Tierra",\
"pas".i.".dat" u 10:11:12 with impulses ls 4 title "Tierra",\
"pas".i.".dat" u 13:14:15 w p ls 5 title "Marte",\
"pas".i.".dat" u 13:14:15 with impulses ls 5 title "Marte",\
"pas".i.".dat" u 16:17:18 w p ls 6 title "Júpiter",\
"pas".i.".dat" u 16:17:18 with impulses ls 6 title "Júpiter"

}
