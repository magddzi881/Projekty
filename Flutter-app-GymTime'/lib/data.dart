import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import './models/category_model.dart';
import './models/exercise_model.dart';

const listOfCategories = const [
  Categoryy(id: 'c1', title: 'Abs Workout', color: Colors.deepPurpleAccent),
  Categoryy(
      id: 'c2', title: 'Lower Body Workout', color: Colors.deepPurpleAccent),
  Categoryy(id: 'c3', title: 'Butt Workout', color: Colors.deepPurpleAccent),
  Categoryy(id: 'c4', title: 'Chest Workout', color: Colors.deepPurpleAccent),
  Categoryy(id: 'c5', title: 'Back Workout', color: Colors.deepPurpleAccent),
  Categoryy(id: 'c6', title: 'Arm Workout', color: Colors.deepPurpleAccent),
  Categoryy(
      id: 'c7', title: 'Full Body Workout', color: Colors.deepPurpleAccent),
];

const listOfExercises = const [
  Exercise(
      isAdvanced: false,
      isEasy: true,
      isForBeginners: false,
      isHard: false,
      id: 'e1',
      title: 'Reverse Crunch',
      categories: ['c1', 'c7'],
      workoutArea: 'Abs',
      complexity: Complexity.Easy,
      duration: 10,
      image:
          'https://www.spotebi.com/wp-content/uploads/2014/10/reverse-crunches-exercise-illustration.jpg',
      preparation: [
        'Lie down with arms extended at your sides and elevate your knees bent at 90 degrees.'
      ],
      steps: [
        'Squeeze absand roll back to bring legs together towards your torso',
        'Keep your hips off the ground',
        'Pause at the top, then return to the starting position'
      ]),
  Exercise(
      isAdvanced: true,
      isEasy: false,
      isForBeginners: false,
      isHard: false,
      id: 'e2',
      title: 'Ski Abs',
      categories: ['c1', 'c2', 'c3'],
      workoutArea: 'Abs',
      complexity: Complexity.Advanced,
      duration: 7,
      image:
          'https://www.spotebi.com/wp-content/uploads/2017/10/ski-abs-exercise-illustration-spotebi.jpg',
      preparation: [
        'Engage your core, maintain your hips keep your back, head, and neck neutral. Exhale as you jump and bring both feet to the front and inhale as you return to the plank position.'
      ],
      steps: [
        'Start with your body in a straight line, your hands slightly wider than shoulder-width apart and feet together.',
        'Bend your knees and jump, bringing both feet to the front and slightly to the left side.',
        'ump again to return to the starting position and then repeat on the right side.',
        'Continue alternating sides until the set is complete.'
      ]),
  Exercise(
      isAdvanced: false,
      isEasy: false,
      isForBeginners: true,
      isHard: false,
      id: 'e3',
      title: 'Ab Stretch',
      categories: ['c1', 'c5', 'c7'],
      workoutArea: 'Abs',
      complexity: Complexity.ForBeginners,
      duration: 3,
      image:
          'https://www.spotebi.com/wp-content/uploads/2014/11/ab-stretch-exercise-illustration.jpg',
      preparation: [
        'Keep your abs and back relaxed and breathe slowly. Inhale as you push your torso up and deepen the stretch. Keep facing forward and maintain your pelvis on the mat. Feel the stretch in your abdominal wall and keep your body in a comfortable and pain-free position.'
      ],
      steps: [
        'Lie face down on your mat with your legs straight and your arms in a push up position',
        'Straighten your arms slowly as you lift your torso',
        'Exhale and pull the wheel back toward yourselt to the starting position',
        'Hold this position for 20 to 30 seconds'
      ]),
  Exercise(
      isAdvanced: false,
      isEasy: false,
      isForBeginners: true,
      isHard: false,
      id: 'e4',
      title: '180 Jump Squat',
      categories: ['c2', 'c3', 'c7'],
      workoutArea: 'Butt',
      complexity: Complexity.ForBeginners,
      duration: 10,
      image:
          'https://www.spotebi.com/wp-content/uploads/2016/12/180-jump-squat-exercise-illustration-spotebi.jpg',
      preparation: [
        'Keep your breathing pattern smooth and steady, and maintain your back aligned by keeping your chest up and your hips back. Put the pressure on the heels of the feet to jump, and land softly on the toes and balls of the feet with your knees slightly bent. As you squat, don’t let the knees extend beyond the toes and tighten your core as you jump back up.'
      ],
      steps: [
        'Stand with your feet a little wider than shoulder-width apart, your toes pointing slightly outward, and sit back.',
        'Push through the heels to jump up, spinning to the left 180 degrees. 3. Land on your toes with your knees slightly bent and squat.',
        'Quickly jump up, spinning to the right, and go back into the squat position.',
        'Repeat until the set is complete.'
      ]),
  Exercise(
      isAdvanced: true,
      isEasy: false,
      isForBeginners: false,
      isHard: false,
      id: 'e5',
      title: 'Alternating Dumbbell Swing',
      categories: ['c6', 'c3'],
      workoutArea: 'Legs',
      complexity: Complexity.Advanced,
      duration: 10,
      image:
          'https://www.spotebi.com/wp-content/uploads/2016/04/alternating-dumbbell-swing-exercise-illustration-spotebi.jpg',
      preparation: [
        'Roll your shoulders back, open your chest, and keep your spine neutral and aligned. Engage your core and breathe in as you lower your hips back and squat. Exhale as you stand back up, squeeze your glutes and switch the dumbbell to your opposite hand.'
      ],
      steps: [
        'Stand with your feet shoulder-width apart, your toes pointed slightly outward, and hold a dumbbell in your right hand.',
        'Squat and bring the dumbbell between your legs.',
        'Stand up, swing the dumbbell up to about chest height, and switch it to your left hand.',
        'Return to the squat position, and keep alternating hands for the duration of the set.'
      ]),
  Exercise(
      isAdvanced: false,
      isEasy: false,
      isForBeginners: false,
      isHard: true,
      id: 'e6',
      title: 'Asymmetrical Push Up',
      categories: ['c1', 'c4', 'c6'],
      workoutArea: 'Chest',
      complexity: Complexity.Hard,
      duration: 15,
      image:
          'https://www.spotebi.com/wp-content/uploads/2016/08/asymmetrical-push-up-exercise-illustration-spotebi.jpg',
      preparation: [
        'Maintain a neutral spine, engage your core muscles and keep your head in line with your torso, and your torso in line with your hips. Breathe in as you lower your chest, and breathe out as you push back up.'
      ],
      steps: [
        'Start in a push up position with your legs extended back and the hands below the shoulders.',
        'Place your left forearm on the mat, with the elbow directly under the shoulder, and start bending your right elbow until your chest is just above the floor.',
        'Push back to the starting position, repeat, and then switch sides.',
      ]),
  Exercise(
      isAdvanced: false,
      isEasy: false,
      isForBeginners: true,
      isHard: false,
      id: 'e7',
      title: 'Reverse Crunch',
      categories: ['c2', 'c5'],
      workoutArea: 'Hips',
      complexity: Complexity.ForBeginners,
      duration: 15,
      image:
          'https://www.spotebi.com/wp-content/uploads/2015/04/split-squat-exercise-illustration.jpg',
      preparation: [
        'When doing split squats, keep your feet hip-width apart, roll your shoulders back and tighten your abs. Breathe in as you lunge, and put your weight in the front heel. Keep the movement smooth and continuous and exhale as you push yourself back up.'
      ],
      steps: [
        'Start in a split leg position, with one leg forward and one leg back.',
        'Flex your knees and lower your hips, until the back knee is just above the floor.',
        ' Stand back up and return to the starting position.',
        'Repeat this movement for as many reps as recommended and then switch legs.'
      ]),
  Exercise(
      isAdvanced: false,
      isEasy: false,
      isForBeginners: false,
      isHard: true,
      id: 'e8',
      title: 'Stability Ball CHest',
      categories: ['c2', 'c5', 'c4', 'c6'],
      workoutArea: 'Chest',
      complexity: Complexity.Hard,
      duration: 20,
      image:
          'https://www.spotebi.com/wp-content/uploads/2016/02/stability-ball-chest-press-exercise-illustration.jpg',
      preparation: [
        'Keep your head and spine in a neutral position, raise the hips, tighten your core and breathe out as you squeeze your chest and push the dumbbells up. Don’t lock your elbows and inhale as you lower the dumbbells until your arms are slightly below parallel to the floor.'
      ],
      steps: [
        'Lie with the middle of your upper back firmly on top of a stability ball, keep your knees bent and hold a dumbbell in each hand.',
        'Push the dumbbells up toward the ceiling, with your palms facing your feet and your arms directly over your shoulders.',
        'Lower your arms down and to the sides and repeat the movement.'
      ]),
  Exercise(
      isAdvanced: false,
      isEasy: true,
      isForBeginners: false,
      isHard: false,
      id: 'e9',
      title: 'Standing Side Crunch',
      categories: ['c1', 'c2', 'c3'],
      workoutArea: 'Hips',
      complexity: Complexity.Easy,
      duration: 15,
      image:
          'https://www.spotebi.com/wp-content/uploads/2015/12/standing-side-crunch-exercise-illustration.jpg',
      preparation: [
        'Keep your spine and neck neutral, your chest up and your core engaged. Breathe out as you crunch and try not to bend your spine forward or swing your hips back and forth.'
      ],
      steps: [
        'Stand with your knees slightly bent, your feet hip-width apart, and your hands behind your head.',
        'Shift your weight to the left leg, crunch to the right side, and bring your right knee up toward your elbow.',
        'Lower your right leg and return to the starting position.',
        'Switch legs and repeat until set is complete.'
      ]),
  Exercise(
      isAdvanced: false,
      isEasy: true,
      isForBeginners: false,
      isHard: false,
      id: 'e10',
      title: 'Superman Twist',
      categories: ['c5', 'c7'],
      workoutArea: 'Back',
      complexity: Complexity.Easy,
      duration: 13,
      image:
          'https://www.spotebi.com/wp-content/uploads/2017/08/superman-twist-exercise-illustration-spotebi.jpg',
      preparation: [
        'Keep your core tight, your spine neutral and engage your back muscles. Exhale as you twist your torso to the side and move only from the ribs up. Pause for 2 seconds and then breathe in as you slowly return to the starting position.'
      ],
      steps: [
        'Lie on your stomach with your legs fully extended, arms bent, and hands behind the ears.',
        'KLift and twist your upper torso to the side and pause for 2 seconds.',
        'Return to the starting position and repeat, twisting your torso to the opposite side.'
      ]),
  Exercise(
      isAdvanced: true,
      isEasy: false,
      isForBeginners: false,
      isHard: false,
      id: 'e11',
      title: 'V Sit Curl Press',
      categories: ['c5', 'c4', 'c6'],
      workoutArea: 'Back',
      complexity: Complexity.Advanced,
      duration: 15,
      image:
          'https://www.spotebi.com/wp-content/uploads/2017/02/v-sit-curl-press-exercise-illustration-spotebi.jpg',
      preparation: [
        'Keep your back straight, engage your core and maintain your head and neck neutral at all times. Breathe out as push the dumbbells up and fully extend your arms and breathe in as you return to the initial position.'
      ],
      steps: [
        'Hold a dumbbell in each hand, sit on the mat and raise your legs to a 45-degree angle.',
        'Squeeze the biceps, lift the dumbbells and curl.',
        'Rotate your palms to the front, push the dumbbells up and fully extend your arms.',
        'Lower your arms back to the starting position and repeat until the set is complete.'
      ]),
];
