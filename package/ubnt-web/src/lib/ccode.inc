<?
	$ccode_include_fail = 0;
	if (fileInode("/etc/ccodes.inc") == -1) {
		global $cmd_regdomain;
		$def_cntry_output = "<option value=\"840\">United States</option>";

		$modestring = " -j -L";
		if ($radio["ieee_mode_a"]) {
			$modestring += " -A";
		}
		if ($radio["ieee_mode_bg"]) {
			$modestring += " -G";
		}
                if ($radio["ccode_locked"] == 2) {
                	$modestring += " -u";
                }
                if ($radio["ccode_fixed"] == 1 || $radio["ccode_locked"] != 0) {
                	$modestring += " "+$radio["ccode"];
                }
		$fd_in = popen ($cmd_regdomain + $modestring, "r");
		if ($fd_in == -1) {
			echo $def_cntry_output;
			$ccode_include_fail = 1;
		}
		$fd_out = fopen("/etc/ccodes.inc", "w");
		if ($fd_out == -1) {
			echo $def_cntry_output;
			$ccode_include_fail = 1;
		}
		$cont = 1;
		while ($cont > 0) {
			$buf = fgets($fd_in, 1024);
			fputs($fd_out, $buf);
			if (!strlen($buf)) { $cont = 0; }
		}
		fclose($fd_out);
		pclose($fd_in);
	}
	if (!$ccode_include_fail) {
		include("/etc/ccodes.inc"); }
>
