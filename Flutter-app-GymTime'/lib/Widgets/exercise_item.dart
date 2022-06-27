import 'package:flutter/material.dart';
import '../models/exercise_model.dart';
import './category_item.dart';
import '../screens/exercise_detail_screen.dart';

class ExerciseItem extends StatelessWidget {
  final String id;
  final String title;
  final String imageUrl;
  final int duration;
  final Complexity complexity;
  final String workoutArea;

  ExerciseItem({
    required this.id,
    required this.title,
    required this.imageUrl,
    required this.complexity,
    required this.duration,
    required this.workoutArea,
  });

  String get complexityText {
    switch (complexity) {
      case Complexity.ForBeginners:
        return 'For beginners';
        break;
      case Complexity.Easy:
        return 'Easy';
        break;
      case Complexity.Advanced:
        return 'Advanced';
        break;
      case Complexity.Hard:
        return 'Hard';
        break;
      default:
        return 'Unknown';
    }
  }

  void selectEx(BuildContext context) {
    Navigator.of(context)
        .pushNamed(
      ExDetailScreen.routeName,
      arguments: id,
    )
        .then((result) {
      if (result != null) {
        // removeItem(result);
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () => selectEx(context),
      child: Card(
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(15),
        ),
        elevation: 4,
        margin: EdgeInsets.all(10),
        child: Column(
          children: <Widget>[
            Stack(
              children: <Widget>[
                ClipRRect(
                  borderRadius: BorderRadius.only(
                    topLeft: Radius.circular(15),
                    topRight: Radius.circular(15),
                  ),
                  child: Image.network(
                    imageUrl,
                    height: 250,
                    width: double.infinity,
                    fit: BoxFit.cover,
                  ),
                ),
                Positioned(
                  bottom: 20,
                  right: 10,
                  child: Container(
                    width: 300,
                    color: Colors.black54,
                    padding: EdgeInsets.symmetric(
                      vertical: 5,
                      horizontal: 20,
                    ),
                    child: Text(
                      title,
                      style: TextStyle(
                        fontSize: 26,
                        color: Colors.white,
                      ),
                      softWrap: true,
                      overflow: TextOverflow.fade,
                    ),
                  ),
                )
              ],
            ),
            Padding(
              padding: EdgeInsets.all(20),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.spaceAround,
                children: <Widget>[
                  Row(
                    children: <Widget>[
                      Icon(
                        Icons.schedule,
                      ),
                      SizedBox(
                        width: 6,
                      ),
                      Text('$duration min'),
                    ],
                  ),
                  Row(
                    children: <Widget>[
                      Icon(
                        Icons.align_vertical_center,
                      ),
                      SizedBox(
                        width: 6,
                      ),
                      Text(complexityText),
                    ],
                  ),
                  Row(
                    children: <Widget>[
                      Icon(
                        Icons.accessibility,
                      ),
                      SizedBox(
                        width: 6,
                      ),
                      Text(workoutArea),
                    ],
                  ),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}
