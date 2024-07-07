echo build_apps.sh
./build_apps.sh
echo update_data.sh
./update_data.sh

echo "preproc && postproc"
python3 ./make_preproc.py
python3 ./make_postproc.py