min_NMAX=100
max_NMAX=10000
step_NMAX=500

versions="1 3"
sizes=$(seq 0 $step_NMAX $max_NMAX)
sizes="$min_NMAX ${sizes:1}"
count=20
if ! [ -d ./data ]; then
    mkdir data
fi
for ver in $versions;do
    for size in $sizes;do
        if [ ! -e ./apps/app"${ver}"_"${size}"_fi.exe ]; then
            gcc -std=c99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
            -Wextra -Wfloat-conversion -Wfloat-equal -o0 \
            -Wvla -o ./apps/app"${ver}"_"${size}"_fi.exe ./src/main"${ver}".c ./src/formal_index_sort.c
        fi

        if [ ! -e ./apps/app"${ver}"_"${size}"_ptr.exe ]; then
            gcc -std=c99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
            -Wextra -Wfloat-conversion -Wfloat-equal -o0 \
            -Wvla -o ./apps/app"${ver}"_"${size}"_ptr.exe ./src/main"${ver}".c ./src/pointer_sort.c
        fi

        if [ ! -e ./apps/app"${ver}"_"${size}"_idx.exe ]; then
            gcc -std=c99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
            -Wextra -Wfloat-conversion -Wfloat-equal -o0 \
            -Wvla -o ./apps/app"${ver}"_"${size}"_idx.exe ./src/main"${ver}".c ./src/index_sort.c
        fi

        if [ ! -e ./data/data"${ver}"_"${size}"_fi.txt ];then
            touch ./data/data"${ver}"_"${size}"_fi.txt || exit
        fi
        ./apps/app"${ver}"_"${size}"_fi.exe >> ./data/data"${ver}"_"${size}"_fi.txt || exit

        if [ ! -e ./data/data"${ver}"_"${size}"_idx.txt ];then
            touch ./data/data"${ver}"_"${size}"_idx.txt || exit
        fi
        ./apps/app"${ver}"_"${size}"_idx.exe >> ./data/data"${ver}"_"${size}"_idx.txt || exit

        if [ ! -e ./data/data"${ver}"_"${size}"_ptr.txt ]; then
            touch ./data/data"${ver}"_"${size}"_ptr.txt || exit
        fi
        ./apps/app"${ver}"_"${size}"_ptr.exe >> ./data/data"${ver}"_"${size}"_ptr.txt || exit
    done
done

