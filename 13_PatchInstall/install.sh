echo "Выберите установить в произвольный каталог(0) или по умолчанию(1)?"
read -r num
echo $num

if [[ "$num" == "1" ]]
then
	cd build
	cmake -S ../ -B ./ -DLOCALE_PATH='/usr/share/locale'
	make
	sudo make install
	sudo make allclean
elif [[ "$num" == "0" ]]
then
	echo "Выберите каталог Для установки"
	read -r path_to_dir
	full_path=$(realpath $path_to_dir)
	echo $full_path
	cmake -S ./ -B $path_to_dir -DLOCALE_PATH=$full_path"/bin"
	cd $full_path
	echo $full_path
	make
fi


