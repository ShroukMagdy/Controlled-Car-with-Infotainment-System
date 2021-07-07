<html>
<head>
<meta name="viewport" content="width=device-width" />
<title>Raspberry Pi WiFi Controlled LED</title>
</head>
       <body>
       <center><h1>Control LED using Raspberry Pi Webserver</h1>      
         <form method="get" action="index.php">                
            <input type="submit" style = "font-size: 14 pt" value="OFF" name="off">
            <input type="submit" style = "font-size: 14 pt" value="ON" name="on">
         </form>​​​
                         </center>
<?php
    shell_exec("/usr/bin/gpio -g mode 23 out");
    if(isset($_GET['off']))
        {
                        echo "LED is off";
                        shell_exec("/usr/bin/gpio -g write 23 0");
        }
            else if(isset($_GET['on']))
            {
                        echo "LED is on";
                        shell_exec("/usr/bin/gpio -g write 23 1");
            }
?>
   </body>
</html>
