import 'package:flutter/material.dart';
import '../models/exercise_model.dart';
import '../Widgets/exercise_item.dart';

class CategoryExercisesScreen extends StatefulWidget {
  static const routeName = '/category-ex';

  final List<Exercise> availableMeals;

  CategoryExercisesScreen(this.availableMeals);

  @override
  CategoryExercisesScreenState createState() => CategoryExercisesScreenState();
}

class CategoryExercisesScreenState extends State<CategoryExercisesScreen> {
  String? categoryTitle;
  List<Exercise>? displayedMeals;
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
      displayedMeals = widget.availableMeals.where((meal) {
        return meal.categories.contains(categoryId);
      }).toList();
      _loadedInitData = true;
    }
    super.didChangeDependencies();
  }

  void _removeMeal(String mealId) {
    setState(() {
      displayedMeals?.removeWhere((meal) => meal.id == mealId);
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
            id: displayedMeals![index].id,
            title: displayedMeals![index].title,
            imageUrl: displayedMeals![index].image,
            duration: displayedMeals![index].duration,
            workoutArea: displayedMeals![index].workoutArea,
            complexity: displayedMeals![index].complexity,
          );
        },
        itemCount: displayedMeals!.length,
      ),
    );
  }
}
