@AllArgsConstructor
@RequiredArgsConstructor
class ResponseEntity<T> {
    private final T data;
    private final int code = 200;
    private final String message = "";

    public static <T> ResponseEntity<T> success(T data) {
        return new ResponseEntity<>(data, 200, "");
    }

    public static ResponseEntity error(int code, String message) {
        return new ResponseEntity<>(null, code, message);
    }
}

@AllArgsConstructor
class Page<T> {
    private final boolean hasNext;
    private final boolean pageSize;
    private final List<T> data;
}

class StudentNotFoundException extends Exception {
    public StudentNotFoundException(String message) {
        super(message);
    }
}

@Data // lombok
@ToString
@AllArgsConstructor
public class Student {
    String name;
    boolean sex;
    int age;
    String class;
}

@Data
@ToString
@AllArgsConstructor
public class Condition<T> {
    T greaterThan;
    T lessThan;
    T equal;
}

@Data
@ToString
@AllArgsConstructor
public class StudentRequestDto {
    int offset;
    int limit;
    String name;
}


@Controller
class StudentController {
    private final StudentService studentService;

    public StudentController(StudentService studentService) {
        this.studentService = studentService;
    }

    // demo: query by name
    @GetMapping("/students")
    public ResponseEntity<Page<Student>> getAllStudents(@QueryParam StudentRequestDto requestDto) {
        try {
            var student = studentService.getStudentByName(requestDto);
            return ResponseEntity.success(student);
        } catch (Exception e) {
            return ResponseEntity.error(500, e.getMessage());
        }
    }
}

@Service
class StudentService {
    private final JDBCTemplate jdbcTemplate;

    public StudentService(JDBCTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    Page<Student> getStudentByName(StudentRequestDto request) throws StudentNotFoundException {
        var sql = "SELECT * FROM student WHERE name = ?";
        var students = jdbcTemplate.query(sql, new Object[]{request.getName()}, new BeanPropertyRowMapper<>(Student.class));
        if (students.isEmpty()) {
            throw new StudentNotFoundException("Student not found");
        }
        return new Page<>(false, false, students);
    }
}
