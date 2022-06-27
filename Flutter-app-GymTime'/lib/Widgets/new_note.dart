//import 'dart:html';

//import 'dart:html';

import 'dart:math';

import 'package:flutter/src/foundation/key.dart';
import 'package:flutter/src/widgets/framework.dart';
import 'package:flutter/material.dart';
import 'package:intl/intl.dart';

class NewNote extends StatefulWidget {
  //const NewTransaction({Key? key}) : super(key: key);
  final Function addTx;

  NewNote(this.addTx);

  @override
  State<NewNote> createState() => NewNoteState();
}

class NewNoteState extends State<NewNote> {
  final _titleController = TextEditingController();

  final _textController = TextEditingController();

  DateTime? _selectedDate;

  void _submitData() {
    if (_textController.text.isEmpty) {
      return;
    }
    final enteredTitle = _titleController.text;
    final enteredText = _textController.text;

    if (enteredTitle.isEmpty || enteredText.isEmpty || _selectedDate == null) {
      return;
    }

    widget.addTx(enteredTitle, enteredText, _selectedDate);
    Navigator.of(context).pop();
  }

  void _presentDatePicker() {
    showDatePicker(
      context: context,
      initialDate: DateTime.now(),
      firstDate: DateTime(2019),
      lastDate: DateTime.now(),
    ).then((pickedDate) {
      if (pickedDate == null) {
        return;
      }
      setState(() {
        _selectedDate = pickedDate;
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return Card(
      elevation: 5,
      child: Container(
          padding: EdgeInsets.all(10),
          child: Column(
              crossAxisAlignment: CrossAxisAlignment.end,
              children: <Widget>[
                TextField(
                  cursorColor: Colors.purple,
                  decoration: InputDecoration(labelText: 'Title'),
                  controller: _titleController,
                  onSubmitted: (_) => _submitData(),
                  // onChanged: (val) {
                  // titleInput = val;
                  //  },
                ),
                TextField(
                  cursorColor: Colors.purple,
                  decoration: InputDecoration(labelText: 'Text'),
                  controller: _textController,
                  //keyboardType: TextInputType.number,
                  onSubmitted: (_) => _submitData(),
                  // onChanged: (val) {
                  // amountInput = val;
                  //  },
                ),
                Container(
                  height: 70,
                  child: Row(
                    children: <Widget>[
                      Expanded(
                        child: Text(_selectedDate == null
                            ? 'No date choosen'
                            : 'Choosen date: ${DateFormat.yMd().format(_selectedDate!)}'),
                      ),
                      FlatButton(
                        textColor: Theme.of(context).primaryColor,
                        child: Text(
                          // textAlign: TextAlign.end,
                          'Change date',
                          style: TextStyle(fontWeight: FontWeight.bold),
                        ),
                        onPressed: _presentDatePicker,
                      )
                    ],
                  ),
                ),
                ElevatedButton(
                  onPressed: _submitData,
                  child: Text('Add note'),
                  //textColor: Colors.white,
                  //color: Colors.deepPurple,
                ),
              ])),
    );
  }
}
