#!/bin/sh
chmod a+x ${0}
usage () {
echo "usage: ${0} <MAN_PAGE>"
echo ''
echo 'MAN_PAGE:'
echo '          mlx -> mlx'
echo '          nw  -> mlx_new_window'
echo '          pp  -> mlx_pixel_put'
echo '          ni  -> mlx_new_image'
echo '          l   -> mlx_loop'
echo 'FILE:'
echo '		keysymdef.h'
echo '		X.h'
echo ''
}
if [ ${#} -ne 1 ] ; then
	usage
else
	if [ ${1} = "mlx" ] ; then
		man /usr/local/man/man3/mlx.1
	elif [ ${1} = "nw" ] ; then
		man /usr/local/man/man3/mlx_new_window.1
	elif [ ${1} = "pp" ] ; then
		man /usr/local/man/man3/mlx_pixel_put.1
	elif [ ${1} = "ni" ] ; then
		man /usr/local/man/man3/mlx_new_image.1
	elif [ ${1} = "l" ] ; then
		man /usr/local/man/man3/mlx_loop.1
	elif [ ${1} = "keysymdef.h" ] ; then
		less /usr/include/X11/keysymdef.h
	elif [ ${1} = "X.h" ] ; then
		less /usr/include/X11/X.h
	else
		usage
	fi
fi
