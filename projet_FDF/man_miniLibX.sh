#!/bin/sh
chmod a+x ${0}
usage () {
echo "usage: ${0} <MAN_PAGE>"
echo ''
echo 'MAN_PAGE:'
echo '          mlx -> mlx'
echo '          mw  -> mlx_new_window'
echo '          pp  -> mlx_pixel_put'
echo '          ni  -> mlx_new_image'
echo '          l   -> mlx_loop'
echo ''
}
if [ ${#} -ne 1 ] ; then
	usage
else
	if [ ${1} = "mlx" ] ; then
		man /usr/share/man/man3/mlx.1
	elif [ ${1} = "nw" ] ; then
		man /usr/share/man/man3/mlx_new_window.1
	elif [ ${1} = "pp" ] ; then
		man /usr/share/man/man3/mlx_pixel_put.1
	elif [ ${1} = "ni" ] ; then
		man /usr/share/man/man3/mlx_new_image.1
	elif [ ${1} = "l" ] ; then
		man /usr/share/man/man3/mlx_loop.1
	else
		usage
	fi
fi
