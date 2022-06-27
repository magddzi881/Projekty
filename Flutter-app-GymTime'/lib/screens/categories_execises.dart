import 'package:flutter/material.dart';
import '../models/exercise_model.dart';
import '../Widgets/exercise_item.dart';

class CategoryExercisesScreen extends StatefulWidget {
  static const routeName = '/category-ex';

  final List<Exercise> available;

  CategoryExercisesScreen(this.available);

  @override
  CategoryExercisesScreenState createState() => CategoryExercisesScreenState();
}

class CategoryExercisesScreenState extends State<CategoryExercisesScreen> {
  String? categoryTitle;
  List<Exercise>? displayed;
  var _loadedInitData = false;

  @override
  void initState() {
    // ...
    super.initState();
  }

  @override
  void didChangeDependencies() {
    if (!_loadedInitData) {
      final routeArgs =
          ModalRoute.of(context)!.settings.arguments as Map<String, String>;
      categoryTitle = routeArgs['title'];
      final categoryId = routeArgs['id'];
      displayed = widget.available.where((ex) {
        return ex.categories.contains(categoryId);
      }).toList();
      _loadedInitData = true;
    }
    super.didChangeDependencies();
  }

  void _removeMeal(String exId) {
    setState(() {
      displayed?.removeWhere((ex) => ex.id == exId);
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(categoryTitle!),
      ),
      body: ListView.builder(
        itemBuilder: (ctx, index) {
          return ExerciseItem(
            id: displayed![index].id,
            title: displayed![index].title,
            imageUrl: displayed![index].image,
            duration: displayed![index].duration,
            workoutArea: displayed![index].workoutArea,
            complexity: displayed![index].complexity,
          );
        },
        itemCount: displayed!.length,
      ),
    );
  }
}
