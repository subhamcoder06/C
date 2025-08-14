<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Car Racing Game</title>
    <link href="https://fonts.googleapis.com/css2?family=Press+Start+2P&display=swap" rel="stylesheet">
    <style>
        body {
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            font-family: 'Press Start 2P', cursive;
            overflow: hidden;
        }

        #gameCanvas {
            border: 2px solid #ddd;
            background-color: #222;
            border-radius: 8px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.5);
        }

        #startButton, #muteButton {
            margin-top: 10px;
            padding: 10px 20px;
            font-size: 1rem;
            cursor: pointer;
            background: linear-gradient(135deg, #6e8efb, #a777e3);
            color: white;
            border: none;
            border-radius: 25px;
            box-shadow: 0px 8px 15px rgba(0, 0, 0, 0.1);
            transition: all 0.3s ease 0s;
            font-family: 'Press Start 2P', cursive;
            outline: none;
            display: inline-flex;
            align-items: center;
            justify-content: center;
            width: 150px;
        }

        #startButton:hover {
            background: linear-gradient(135deg, #4364f7, #6200ea);
            box-shadow: 0px 15px 20px rgba(46, 229, 157, 0.4);
            transform: translateY(-3px);
        }

        #startButton:active {
            transform: translateY(1px);
            box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.2);
        }

        #muteButton {
            margin-left: 10px;
        }

        #muteButton:hover {
            transform: translateY(-3px);
        }

        #muteButton:active {
            transform: translateY(1px);
        }

        .hidden {
            display: none;
        }

        #gameOverScreen {
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background-color: rgba(0, 0, 0, 0.8);
            display: none;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            z-index: 10;
        }

        #gameOverScreen h2 {
            font-size: 2rem;
            color: #fff;
            margin-bottom: 20px;
        }

        #gameOverScreen p {
            font-size: 1.2rem;
            color: #eee;
            margin-bottom: 30px;
        }

        #newGameButton {
            padding: 12px 24px;
            font-size: 1.1rem;
            cursor: pointer;
            background: linear-gradient(135deg, #f6d365, #fda085);
            color: #121212;
            border: none;
            border-radius: 30px;
            box-shadow: 0px 8px 15px rgba(0, 0, 0, 0.1);
            transition: all 0.3s ease 0s;
            font-family: 'Press Start 2P', cursive;
            outline: none;
        }

        #newGameButton:hover {
            background: linear-gradient(135deg, #f4d03f, #f57c00);
            box-shadow: 0px 15px 20px rgba(232, 146, 5, 0.4);
            transform: translateY(-3px);
        }

        #newGameButton:active {
            transform: translateY(1px);
            box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.2);
        }

        #scoreDisplay {
            position: absolute;
            top: 20px;
            left: 50%;
            transform: translateX(-50%);
            color: #fff;
            font-size: 1.5rem;
            z-index: 10;
            padding: 10px;
            border-radius: 8px;
            background-color: rgba(0, 0, 0, 0.5);
        }

        .blinking {
            animation: blinker 1s linear infinite;
        }

        @keyframes blinker {
            50% { opacity: 0; }
        }

        #instructionScreen {
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background-color: rgba(0, 0, 0, 0.85);
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            z-index: 11;
            padding: 20px;
            box-sizing: border-box;
            text-align: center;
        }

        #instructionScreen h2 {
            font-size: 1.8rem;
            color: #fff;
            margin-bottom: 1rem;
            text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.7);
        }

        #instructionScreen p {
            font-size: 1rem;
            color: #eee;
            margin-bottom: 1.5rem;
            line-height: 1.5;
            text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.5);
        }

        #instructionScreen ul {
            list-style: none;
            padding: 0;
            margin-bottom: 2rem;
            font-size: 1rem;
            color: #eee;
            text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.5);
        }

        #instructionScreen li {
            margin-bottom: 0.5rem;
        }

        #instructionScreen button {
            padding: 0.75rem 1.5rem;
            font-size: 1rem;
            cursor: pointer;
            background: linear-gradient(135deg, #00b09b, #96c93d);
            color: #fff;
            border: none;
            border-radius: 25px;
            box-shadow: 0px 8px 15px rgba(0, 0, 0, 0.3);
            transition: all 0.3s ease 0s;
            font-family: 'Press Start 2P', cursive;
            outline: none;
        }

        #instructionScreen button:hover {
            background: linear-gradient(135deg, #00897b, #74b72e);
            box-shadow: 0px 15px 20px rgba(0, 0, 0, 0.4);
            transform: translateY(-3px);
        }

        #instructionScreen button:active {
            transform: translateY(1px);
            box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.2);
        }

        .shake {
          animation: shake 0.5s;
        }

        @keyframes shake {
          0% { transform: translateX(0); }
          25% { transform: translateX(-5px); }
          50% { transform: translateX(5px); }
          75% { transform: translateX(-5px); }
          100% { transform: translateX(0); }
        }
    </style>
</head>
<body>
    <div id="instructionScreen">
        <h2>How to Play</h2>
        <ul>
            <li>Use the left and right arrow keys to control your car.</li>
            <li>Avoid obstacles (other cars).</li>
            <li>The game speeds up as you progress.</li>
            <li>Try to get the highest score!</li>
        </ul>
        <button id="startRaceButton">Start Game</button>
    </div>
    <canvas id="gameCanvas" width="320" height="480"></canvas>
    <div id="scoreDisplay" class="blinking">Score: 0</div>
    <div id="startButton" class="hidden">Start</div>
    <button id="muteButton">
        <img id="muteIcon" src="https://cdn.jsdelivr.net/npm/lucide-static@latest/icons/volume-2.svg" />
    </button>

    <div id="gameOverScreen" class="hidden">
        <h2>Game Over</h2>
        <p id="finalScoreDisplayScreen">Your Score: 0</p>
        <button id="newGameButton">New Game</button>
    </div>

    <script src="https://cdnjs.cloudflare.com/ajax/libs/tone/14.8.49/Tone.js"></script>
    <script>
       const canvas = document.getElementById('gameCanvas');
        const ctx = canvas.getContext('2d');
        const startButton = document.getElementById('startButton');
        const muteButton = document.getElementById('muteButton');
        const muteIcon = document.getElementById('muteIcon');
        const gameOverScreen = document.getElementById('gameOverScreen');
        const newGameButton = document.getElementById('newGameButton');
        const scoreDisplay = document.getElementById('scoreDisplay');
        const finalScoreDisplayScreen = document.getElementById('finalScoreDisplayScreen');
        const instructionScreen = document.getElementById('instructionScreen');
        const startRaceButton = document.getElementById('startRaceButton');

        let playerCar;
        let obstacles = [];
        let score = 0;
        let gameSpeed = 3;
        let animationId;
        let isMuted = false;
        let gameRunning = false;
        let obstacleInterval = 1000;
        let lastObstacleTime = 0;
        let playerSpeed = 5;

        // --- Sound Effects (Tone.js) ---
        const carEngineSound = new Tone.Synth({
            oscillator: { type: 'sine' },
            envelope: { attack: 0.01, decay: 0.1, sustain: 0.3, release: 1 }
        }).toDestination();

        const collisionSound = new Tone.Synth({
            oscillator: { type: 'square' },
            envelope: { attack: 0.001, decay: 0.1, sustain: 0.01, release: 0.1 }
        }).toDestination();

        const gameOverSound = new Tone.MembraneSynth({
            pitchDecay: 0.05,
            octaves: 10,
            oscillator: { type: 'sine' },
            envelope: { attack: 0.001, decay: 0.4, sustain: 0.01, release: 1.4, attackCurve: 'exponential' }
        }).toDestination();


        let engineSoundPlaying = false;

        function playCarEngineSound() {
            if (!isMuted && !engineSoundPlaying) {
                carEngineSound.triggerAttack(440);
                engineSoundPlaying = true;
            }
        }

        function stopCarEngineSound() {
            if (engineSoundPlaying) {
                carEngineSound.triggerRelease();
                engineSoundPlaying = false;
            }
        }

        function playCollisionSound() {
            if (!isMuted) {
                collisionSound.triggerAttackRelease("C4", "8n");
            }
        }

        function playGameOverSound() {
            if (!isMuted) {
                gameOverSound.triggerAttackRelease("A2", "2n");
            }
        }

        // --- Helper Functions ---

        function random(min, max) {
            return Math.floor(Math.random() * (max - min + 1)) + min;
        }

        // --- Game Object Creation ---

        function createPlayer() {
            return {
                x: canvas.width / 2 - 20,
                y: canvas.height - 60,
                width: 40,
                height: 60,
                color: 'white',
                speed: playerSpeed,
                lives: 3
            };
        }

        function createObstacle(x = null) {
            const minX = 30;
            const maxX = canvas.width - 30 - 20;
            return {
                x: x === null ? random(minX, maxX) : x,
                y: -50,
                width: 30,
                height: 50,
                color: `hsl(${random(0, 360)}, 100%, 50%)`,
                speed: gameSpeed,
                passed: false,
                type: 'car'
            };
        }

        // --- Drawing Functions ---

        function drawPlayer() {
            ctx.fillStyle = playerCar.color;
            ctx.fillRect(playerCar.x, playerCar.y, playerCar.width, playerCar.height);
        }

        function drawObstacle(obstacle) {
            ctx.fillStyle = obstacle.color;
            ctx.fillRect(obstacle.x, obstacle.y, obstacle.width, obstacle.height);
        }

        function drawScore() {
            scoreDisplay.textContent = `Score: ${score}`;
        }

        // --- Update Functions ---
        function updatePlayer() {
            if (keys['ArrowLeft'] && playerCar.x > 0) {
                playerCar.x -= playerCar.speed;
            }
            if (keys['ArrowRight'] && playerCar.x < canvas.width - playerCar.width) {
                playerCar.x += playerCar.speed;
            }
             if (keys['Space']) {
                playerCar.speed = 10;
                setTimeout(() => {
                    playerCar.speed = playerSpeed;
                }, 500);
            }
        }

        function updateObstacles() {
            if (obstacles.length === 0 || Date.now() - lastObstacleTime > obstacleInterval) {
                obstacles.push(createObstacle());
                lastObstacleTime = Date.now();
                if (obstacleInterval > 200) {
                    obstacleInterval -= 50;
                }
            }

            obstacles.forEach(obstacle => {
                obstacle.y += obstacle.speed / 2;

                if (obstacle.y > playerCar.y && !obstacle.passed) {
                    obstacle.passed = true;
                    score += 10;
                    drawScore();
                }
            });

            obstacles = obstacles.filter(obstacle => obstacle.y < canvas.height);
        }

        function checkCollision() {
            for (let obstacle of obstacles) {
                if (
                    playerCar.x < obstacle.x + obstacle.width &&
                    playerCar.x + playerCar.width > obstacle.x &&
                    playerCar.y < obstacle.y + obstacle.height &&
                    playerCar.y + playerCar.height > obstacle.y
                ) {
                    playCollisionSound();
                    playerCar.lives--;
                    if (playerCar.lives <= 0) {
                        gameOver();
                        return true;
                    } else {
                        obstacles.splice(obstacles.indexOf(obstacle), 1);
                        obstacles.push(createObstacle(obstacle.x));
                        playerCar.x = canvas.width / 2 - 20;
                        playerCar.y = canvas.height - 60;
                        return false;
                    }
                }
            }
            return false;
        }

        function updateGameSpeed() {
            if (score > 500) {
                gameSpeed = 4;
            }
            if (score > 1000) {
                gameSpeed = 5;
            }
            if (score > 2000) {
                gameSpeed = 6;
            }
            if (score > 3000) {
                gameSpeed = 7;
            }
        }

        // --- Input Handling ---

        let keys = {};

        document.addEventListener('keydown', (e) => {
            keys[e.code] = true;
            if (e.code === 'ArrowLeft' || e.code === 'ArrowRight') {
                e.preventDefault();
            }
            playCarEngineSound();
        });

        document.addEventListener('keyup', (e) => {
            keys[e.code] = false;
            stopCarEngineSound();
        });

        // --- Game Loop ---
        function gameLoop() {
            if (!gameRunning) return;

            ctx.clearRect(0, 0, canvas.width, canvas.height);
            updatePlayer();
            updateObstacles();
            updateGameSpeed();

            drawPlayer();
            obstacles.forEach(drawObstacle);
            drawScore();

            if (checkCollision()) {
                return;
            }

            animationId = requestAnimationFrame(gameLoop);
        }

        // --- Game Start/End ---

        function startGame() {
            if (animationId) cancelAnimationFrame(animationId);
            instructionScreen.classList.add('hidden');
            gameOverScreen.classList.add('hidden');
            startButton.classList.add('hidden');
            gameRunning = true;
            playerCar = createPlayer();
            obstacles = [];
            score = 0;
            gameSpeed = 3;
            obstacleInterval = 1000;
            drawScore();
            gameLoop();
            playCarEngineSound();
        }

        function gameOver() {
            gameRunning = false;
            stopCarEngineSound();
            playGameOverSound();
            cancelAnimationFrame(animationId);
            finalScoreDisplayScreen.textContent = `Your Score: ${score}`;
            gameOverScreen.classList.remove('hidden');
            newGameButton.focus();
            obstacleInterval = 1000;

        }

        function toggleMute() {
            isMuted = !isMuted;
            muteIcon.src = isMuted
                ? "https://cdn.jsdelivr.net/npm/lucide-static@latest/icons/volume-x.svg"
                : "https://cdn.jsdelivr.net/npm/lucide-static@latest/icons/volume-2.svg";
        }

        // --- Event Listeners ---

        newGameButton.addEventListener('click', startGame);
        muteButton.addEventListener('click', toggleMute);
        startRaceButton.addEventListener('click', startGame);

        // --- Initial Setup ---

        window.onload = function() {
            // All initial setup that relies on the DOM should be done here
            newGameButton.addEventListener('click', startGame);
            muteButton.addEventListener('click', toggleMute);
            startRaceButton.addEventListener('click', startGame);
        };
    </script>
</body>
</html>

