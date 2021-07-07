<html>
        <body>
                <p>A function is triggered when the user is pressing a key in the input field.</p>
                <p>onkeyup - <span id="released"></span></p>
                <p>onkeydown - <span id="pressed"></span></p>
                <script>
                        document.addEventListener('keydown', function (event) {
                                var key = event.key;
                                if (key === "ArrowUp"){
                                        document.getElementById("pressed").innerHTML = "The KEY: " + key;
                                }
                                else if (key === "ArrowDown"){
                                        document.getElementById("pressed").innerHTML = "The KEY: " + key;
                                }
                                else if (key === "ArrowRight"){
                                        document.getElementById("pressed").innerHTML = "The KEY: " + key;
                                }
                                else if (key === "ArrowLeft"){
                                        document.getElementById("pressed").innerHTML = "The KEY: " + key;
                                }
                        });
                        document.addEventListener('keyup', function (event) {
                                var key = event.key;
                                if (key === "ArrowUp"){
                                        document.getElementById("released").innerHTML = "The KEY: " + key;
                                }
                                else if (key === "ArrowDown"){
                                        document.getElementById("released").innerHTML = "The KEY: " + key;
                                }
                                else if (key === "ArrowRight"){
                                        document.getElementById("released").innerHTML = "The KEY: " + key;
                                }
                                else if (key === "ArrowLeft"){
                                        document.getElementById("pressed").innerHTML = "The KEY: " + key;
                                }
                        });

                </script>
        </body>
</html>
