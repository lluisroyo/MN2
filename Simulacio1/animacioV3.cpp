set terminal gif animate delay 2 size 1000, 1000
set output "D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/animacio2.gif"

set key right top 
set key font ",25"
set key spacing 3

set style line 1 lc rgb "#e88900" lw 1 lt 1 pt 7 ps 3 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #sol
set style line 2 lc rgb "#a79e91" lw 1 lt 1 pt 7 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #mercuri
set style line 3 lc rgb "#b99664" lw 1 lt 1 pt 7 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #venus
set style line 4 lc rgb "#05ffc6" lw 1 lt 1 pt 7 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #terra
set style line 5 lc rgb "#b93c10" lw 1 lt 1 pt 7 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #mart
set style line 6 lc rgb "#daaf00" lw 1 lt 1 pt 7 ps 2 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #jupiter
set style line 7 lc rgb "#b63f00" lw 1 lt 1 pt 7 ps 3 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #gliese
set style line 8 lc rgb "#2de300" lw 1 lt 1 pt 7 ps 3 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size) #pla de la orbita
f(x,y)= 0


do for [i=1:49999]{
set ticslevel 0.0
set view equal xyz
set view 60,20
set xlabel "x/Rj"
set ylabel "y/Rj"
set ztics 
set zlabel "z/Rj"
set xrange[-5.0:5.0]
set yrange[-5.0:5.0]
set zrange[-5.0:5.0]

splot f(x,y) w l ls 8 title "Plano de la orbita inicial",\
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 19:20:21 w p ls 7 title "Gliese 710",\
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 19:20:21 with impulses ls 7 notitle,\
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 1:2:3 w p ls 1 title "Sol", \
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 1:2:3 with impulses ls 1 notitle, \
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 4:5:6 w p ls 2 title "Mercurio", \
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 4:5:6 with impulses ls 2 notitle,\
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 7:8:9 w p ls 3 title "Venus", \
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 7:8:9 with impulses ls 3 notitle, \
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 10:11:12 w p ls 4 title "Tierra", \
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 10:11:12 with impulses ls 4 notitle, \
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 13:14:15 w p ls 5 title "Marte", \
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 13:14:15 with impulses ls 5 notitle, \
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 16:17:18 w p ls 6 title "Júpiter", \
"D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/pas".(20*i).".dat" u 16:17:18 with impulses ls 6 notitle

}
