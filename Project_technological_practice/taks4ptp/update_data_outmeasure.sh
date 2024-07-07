min_NMAX=100
max_NMAX=10000
step_NMAX=500

versions="1 2"
sizes=$(seq 0 $step_NMAX $max_NMAX)
sizes="$min_NMAX ${sizes:1}"
count=20
if ! [ -d ./data ]; then
    mkdir data
fi

# main2.c
for size in $sizes;do
    if [ ! -e ./apps/app2_"${size}"_fi.exe ]; then
        gcc -std=c99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
        -Wextra -Wfloat-conversion -Wfloat-equal -o0 \
        -Wvla -o ./apps/app2_"${size}"_fi.exe ./src/main2.c ./src/formal_index_sort.c
    fi

    if [ ! -e ./apps/app2_"${size}"_ptr.exe ]; then
        gcc -std=c99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
        -Wextra -Wfloat-conversion -Wfloat-equal -o0 \
        -Wvla -o ./apps/app2_"${size}"_ptr.exe ./src/main2.c ./src/pointer_sort.c
    fi

    if [ ! -e ./apps/app2_"${size}"_idx.exe ]; then
        gcc -std=c99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
        -Wextra -Wfloat-conversion -Wfloat-equal -o0 \
        -Wvla -o ./apps/app2_"${size}"_idx.exe ./src/main2.c ./src/index_sort.c
    fi

    if [ ! -e ./data/data2_"${size}"_fi.txt ];then
        touch ./data/data2_"${size}"_fi.txt
    fi
    while python3 ./scripts/rse.py ./data/data2_"${size}"_fi.txt;do
        ./apps/app1_"${size}"_fi.exe >> ./data/data2_"${size}"_fi.txt || exit
    done



    if [ ! -e ./data/data2_"${size}"_idx.txt ];then
        touch ./data/data2_"${size}"_idx.txt
    fi
    while python3 ./scripts/rse.py ./data/data2_"${size}"_idx.txt;do
        ./apps/app1_"${size}"_idx.exe >> ./data/data2_"${size}"_idx.txt || exit
    done

    
    if [ ! -e ./data/data2_"${size}"_ptr.txt ]; then
        touch ./data/data2_"${size}"_ptr.txt
    fi
    while python3 ./scripts/rse.py ./data/data2_"${size}"_ptr.txt ;do
        ./apps/app1_"${size}"_ptr.exe >> ./data/data2_"${size}"_ptr.txt || exit
    done
done
