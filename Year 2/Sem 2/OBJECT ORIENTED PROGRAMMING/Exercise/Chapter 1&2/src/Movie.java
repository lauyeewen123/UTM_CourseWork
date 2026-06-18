public class Movie {
    private String title;
    private String genre;
    private double rating;

    public Movie(String t, String g, double r) {
        title = t;
        genre = g;
        rating = r;
    }

    public void printMovieInfo(){
        System.out.println("Title: " + title +", Genre: " + genre + ", Rating: " + rating + "\n");
    }

    public static void main(String args[]) {
        Movie m1 = new Movie ("Ne-zha", "Anime",8.5);
        Movie m2 = new Movie ("Little Mermaid", "Cartoon", 9.3);

        m1.printMovieInfo();
        m2.printMovieInfo();
    }
}
